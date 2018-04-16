let move = (player: Types.player, action: Actions.all) => {
  let newPlayer = switch action {
    | LeftPlayerGoDown | RightPlayerGoDown => {
        ...player,
        y: player.y +. 10.,
      }
    | LeftPlayerGoUp | RightPlayerGoUp => {
        ...player,
        y: player.y -. 10.,
      }
    | _ => player
  };
  Js.log(newPlayer);
  newPlayer;
};

let reducer = (state: Types.playersState, action: Actions.all) => switch action {
  | LeftPlayerGoDown | LeftPlayerGoUp => {
    ...state,
    leftPlayer: move(state.leftPlayer, action),
  }
  | RightPlayerGoDown | RightPlayerGoUp => {
    ...state,
    rightPlayer: move(state.rightPlayer, action),
  }
  | _ => state
};