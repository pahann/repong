
open Webapi.Canvas.Canvas2d;


let onKeyDown = (keyCode: string) : unit =>
  switch keyCode {
  | "ArrowUp" => {
    Store.dispatch(LeftPlayerGoUp);
    Store.dispatch(RightPlayerGoUp);
  }
  | "ArrowDown" => {
    Store.dispatch(LeftPlayerGoDown);
    Store.dispatch(RightPlayerGoDown);
  }
  | _ => Js.log("no matched keycode: " ++ keyCode); ()
  };

let render = (ctx, state: Types.player) => {
  setFillStyle(ctx, String, "black");
  ctx |> fillRect(~x=state.x, ~y=state.y, ~w=state.paddleThickness, ~h=state.paddleWidth);
  ();
};
