
[@bs.val] external pi : float = "Math.PI";

open Webapi.Canvas.Canvas2d;


let render = (ctx, state: Types.ballState) => {
  setFillStyle(ctx, String, "black");
  beginPath(ctx);
  arc(ctx, ~x=state.x, ~y=state.y, ~startAngle=state.size *. 5., ~endAngle=0., ~r=state.size *. pi, ~anticw=true);
  fill(ctx);
};
