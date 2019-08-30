open Webapi.Dom;
open Webapi.Canvas.Canvas2d;

[@bs.set]
external setWidth : (Dom.element, float) => unit = "width";

[@bs.set]
external setHeight : (Dom.element, float) => unit = "height";


let onKeyDownWrapper = (event: Dom.keyboardEvent) =>
  switch (Webapi.Dom.KeyboardEvent.code(event)) {
  | keyCode => Paddle.onKeyDown(keyCode)
  | _ => ()
  };

let domSetup = (canvasElt, state: Types.screenState) => {
  /* setWidth(canvasElt, Window.innerWidth(window) - 50);
  setHeight(canvasElt, Window.innerHeight(window) - 50); */
  setWidth(canvasElt, state.width);
  setHeight(canvasElt, state.height);
  Document.addKeyDownEventListener(onKeyDownWrapper, document);
  ();
};

let drawBg = (ctx, state: Types.screenState) => {
  setFillStyle(ctx, String, "white");
  fillRect(ctx, ~x=0., ~y=0., ~w=state.width, ~h=state.height);

  beginPath(ctx);
  ctx |> moveTo(~y=-1., ~x=state.width /. 2.);
  ctx |> lineTo(~y=state.height, ~x=state.width /. 2.);
  stroke(ctx);
};

let render = (ctx, state: Types.rootState) => {
  let players = state.players;
  drawBg(ctx, state.screen);
  Ball.render(ctx, state.ball);
  Paddle.render(ctx, players.leftPlayer);
  Paddle.render(ctx, players.rightPlayer);
}
