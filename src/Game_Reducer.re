open Types;


[@bs.val] [@bs.scope "Math"]
external abs : float => float = "abs";


let isBallLost = (ball: ballState, screen: screenState) => {
  ball.x <= 0. || ball.x >= screen.width
};

let recenterBall = (ball: ballState, screen: screenState) => {
  ...ball,
  x: screen.width /. 2.,
  y: screen.height /. 2.,
  xSpeed: if (ball.xSpeed < 0.) 1.8 else -1.8,
  ySpeed: 0.,
};

let isBallOnTopEdge = (ball: ballState, _screen: screenState) => {
  ball.y -. ball.size <= 0. && ball.ySpeed < 0.
};

let isBallOnBottomEdge = (ball: ballState, screen: screenState) => {
  ball.y +. ball.size >= screen.height && ball.ySpeed > 0.
};

let edgeBounce = (ball: ballState) => {
  ...ball,
  xSpeed: ball.xSpeed *. 1.01,
  ySpeed: ball.ySpeed *. -0.99,
};

let isBallOnPaddle = (ball: ballState, player: player) => {
  ball.y >= player.y && ball.y <= player.y +. player.paddleWidth;
};

let isBallOnLeftPlayer = (ball: ballState, players: playersState) => {
  let player = players.leftPlayer;
  ball.x -. (ball.size) <= player.x +. player.paddleThickness
    && isBallOnPaddle(ball, player);
};

let isBallOnRightPlayer = (ball: ballState, players: playersState) => {
  let player = players.rightPlayer;
  ball.x >= player.x
    && isBallOnPaddle(ball, player);
};

let playerBounce = (ball: ballState, player: player) => {
  let halfPaddle = player.paddleWidth /. 2.;
  let paddleBasedY = (ball.y -. player.y -. halfPaddle) /. -10.;
  {
    ...ball,
    xSpeed: ball.xSpeed *. -1.,
    ySpeed: paddleBasedY *. -1.,
  };
};

let postReducer = (state: rootState, action: Actions.all) => {
  switch action {
    | Tick => {
      switch (state.ball, state.screen, state.players) {
        | (ball, screen, _) when isBallLost(ball, screen) => {
            ...state,
            ball: recenterBall(ball, screen),
        }
        | (ball, screen, _) when isBallOnTopEdge(ball, screen)   => {
          ...state,
          ball: edgeBounce(ball),
        }
        | (ball, screen, _) when isBallOnBottomEdge(ball, screen)   => {
          ...state,
          ball: edgeBounce(ball),
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
