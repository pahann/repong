let reducer = (state: Types.screenState, action: Actions.all): Types.screenState => switch action {
  | SetCanvasSize(size) => {
    height: size.height,
    width: size.width,
  }
  | _ => state
};
