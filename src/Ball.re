
[@bs.val] external pi : float = "Math.PI";

open Webapi.Canvas.Canvas2d;

// TODO: check ball rendering: why do we need this trick on ball size ?
let render = (ctx, state: Types.ballState) => {
  setFillStyle(ctx, String, "black");
  beginPath(ctx);
  arc(ctx, ~x=state.x, ~y=state.y, ~startAngle=state.size *. 4., ~endAngle=0., ~r=(state.size -. 1.) *. pi, ~anticw=true);
  fill(ctx);
};
