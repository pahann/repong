[@bs.val] [@bs.scope "Math"]
external abs : float => float = "abs";


let isBallLost = (ball: Types.ballState, screen: Types.screenState) => {
  ball.x <= 0. || ball.x >= screen.width
};

let recenterBall = (ball: Types.ballState, screen: Types.screenState) => {
  ...ball,
  x: screen.width /. 2.,
  y: screen.height /. 2.,
  xSpeed: if (ball.xSpeed < 0.) 1.8 else -1.8,
  ySpeed: 0.,
};

let isBallOnEdges = (ball: Types.ballState, screen: Types.screenState) => {
  ball.y <= 0. || ball.y >= screen.height
};

let edgeBounce = (ball: Types.ballState) => {
  ...ball,
  xSpeed: ball.xSpeed *. 1.01,
  ySpeed: ball.ySpeed *. -0.99,
};

let isBallOnPaddle = (ball: Types.ballState, player: Types.player) => {
  ball.y >= player.y && ball.y <= player.y +. player.paddleWidth;
};

let areCloseEnough = (first: float, second: float) => abs(first -. second) < 2.0;

let isBallOnLeftPlayer = (ball: Types.ballState, players: Types.playersState) => {
  let player = players.leftPlayer;
  ball.x <= player.x
    /* && areCloseEnough(ball.x, player.x +. player.paddleThickness) */
    && isBallOnPaddle(ball, player);
};

let isBallOnRightPlayer = (ball: Types.ballState, players: Types.playersState) => {
  let player = players.rightPlayer;
  ball.x >= player.x
    /* && areCloseEnough(ball.x +. ball.size, player.x) */
    && isBallOnPaddle(ball, player);
};

let playerBounce = (ball: Types.ballState, player: Types.player) => {
  let halfPaddle = player.paddleWidth /. 2.;
  let paddleBasedY = (ball.y -. player.y -. halfPaddle) /. -10.;
  {
    ...ball,
    xSpeed: ball.xSpeed *. -1.,
    ySpeed: paddleBasedY *. -1.,
  };
};

let preReducer = (state: Types.rootState, action: Actions.all) => {
  switch action {
    | Tick => {
      switch (state.ball, state.screen, state.players) {
        | (ball, screen, _) when isBallLost(ball, screen) => {
            ...state,
            ball: recenterBall(ball, screen),
        }
        | (ball, screen, _) when isBallOnEdges(ball, screen)   => {
          ...state,
          ball: edgeBounce(state.ball),
        }
        | (ball, _, players) when isBallOnLeftPlayer(ball, players)   => {
          ...state,
          ball: playerBounce(ball, players.leftPlayer),
        }
        | (ball, _, players) when isBallOnRightPlayer(ball, players)   => {
          ...state,
          ball: playerBounce(ball, players.rightPlayer),
        }
        | _ => state
      };
    }
    | _ => state
  }
};
