let reducer = (state: Types.ballState, action: Actions.all) => switch action {
  | Tick => {
    ...state,
    x: state.x +. state.xSpeed,
    y: state.y +. state.ySpeed,
  }
  | _ => state
};
