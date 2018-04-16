# REPong
I built this project to play a bit with ReasonML =)

The main reducers loop is directly inspired by this cool workshop =>     https://github.com/js-republic/reason-ml-workshop

Here's you can play: https://keen-lovelace-01378a.netlify.com/  (very simplistic and mono player for now)

Run this project:

```
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up the nested html files in `build/*` (**no server needed!**). Then modify whichever file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example


## Roadmap:
- [x] Basic pong with a single player
- [ ] Display scores
- [ ] Handle multi player with a WebRTC channel
- [ ] Try a more than one player pong concept
