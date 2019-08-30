type storeType('state) = {
  mutable actions: list(Actions.all),
  mutable state: 'state,
};

let gameWidth = 600.;
let gameHeight = 400.;
let paddleThickness = 8.;
let paddleWidth = 60.;
let ballSize = 3.;

let store: storeType(Types.rootState) = {
  actions: [],
  state:
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
      (state: Types.rootState, action) => {
        let newState: Types.rootState = {
          screen: Screen_reducer.reducer(state.screen, action),
          ball: Ball_reducer.reducer(state.ball, action),
          players: Players_reducer.reducer(state.players, action)
        };
        Game_Reducer.postReducer(newState, action);
      },
      store.state,
      store.actions
    );
  store.actions = [];
  ();
};

let dispatch = (action: Actions.all) : unit =>
  store.actions = store.actions @ [action];