type canvasSize = {
  width: float,
  height: float,
};

type player = {
  x: float,
  y: float,
  paddleWidth: float,
  paddleThickness: float,
};

type playersState = {
  leftPlayer: player,
  rightPlayer: player,
};

type ballState = {
  x: float,
  y: float,
  xSpeed: float,
  ySpeed: float,
  size: float,
};


type screenState = {
  width: float,
  height: float,
};

type rootState = {
  screen: screenState,
  ball: ballState,
  players: playersState,
};
