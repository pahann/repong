const path = require('path');

module.exports = {
  entry: './src/Main.bs.js',
  output: {
    path: path.join(__dirname, "build"),
    filename: 'index.js',
  },
  optimization: {
    minimize: false
  },
};
