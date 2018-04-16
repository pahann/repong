open Webapi.Dom;
open Store;

let rec onFrame = (ctx, _) => {
  Store.dispatch(Tick);
  applyReducers();
  Viewport.render(ctx, store.state);
  Webapi.requestAnimationFrame(onFrame(ctx));
};

let runGame = (canvasElt: Dom.element) => {
  Viewport.domSetup(canvasElt, store.state.screen);
  let ctx = Webapi.Canvas.CanvasElement.getContext2d(canvasElt);
  Webapi.requestAnimationFrame(onFrame(ctx));
};

switch (Webapi.Dom.Document.getElementById("game", Webapi.Dom.document)) {
  | Some(canvasElt) => runGame(canvasElt);
  | None => failwith("No canvas root");
};
