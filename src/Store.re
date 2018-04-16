type storeType('state) = {
  mutable actions: list(Actions.all),
  mutable state: 'state,
};

let gameWidth = 600.;
let gameHeight = 400.;
let paddleThickness = 8.;
let paddleWidth = 60.;
let ballSize = 2.;

let store: storeType(Types.rootState) = {
  actions: [],
  /* "rootState" état global du système de type Types.rootState */
  state:
    /* "screen" définie l'état de l'écran (pas utile pour vous) de type Types.screenState */
    {
      screen: {
        width: gameWidth,
        height: gameHeight,
      },
      ball: {
        x: 0.,
        y: 0.,
        xSpeed: 0.,
        ySpeed: 0.,
        size: ballSize,
      },
      players: {
        leftPlayer: {
          x: 2.,
          y: gameHeight /. 2. -. paddleWidth /. 2.,
          paddleWidth: paddleWidth,
          paddleThickness: paddleThickness,
        },
        rightPlayer: {
          x: gameWidth -. paddleThickness -. 2.,
          y: gameHeight /. 2. -. paddleWidth /. 2.,
          paddleWidth: paddleWidth,
          paddleThickness: paddleThickness,
        },
      }
    },
};

let applyReducers = () : unit => {
  store.state =
    List.fold_left(
      (state: Types.rootState, action) => { /* Why bad inference in this state case ? */
        let preState = Game_Reducer.preReducer(state, action);
        let newState: Types.rootState = {
          screen: Screen_reducer.reducer(preState.screen, action),
          ball: Ball_reducer.reducer(preState.ball, action),
          players: Players_reducer.reducer(preState.players, action)
        };
        newState;
      },
      store.state,
      store.actions
    );
  store.actions = [];
  ();
};

let dispatch = (action: Actions.all) : unit =>
  store.actions = store.actions @ [action];