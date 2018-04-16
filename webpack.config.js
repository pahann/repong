const path = require('path');
const CopyWebpackPlugin = require('copy-webpack-plugin');

module.exports = {
  entry: './src/Main.bs.js',
  output: {
    path: path.join(__dirname, "build"),
    filename: 'index.js',
  },
  optimization: {
    minimize: false
  },
  plugins: [
    new CopyWebpackPlugin([
        { from: 'public' }
    ])
  ]
};
