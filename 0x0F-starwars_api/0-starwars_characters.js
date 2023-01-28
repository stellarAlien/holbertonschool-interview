#!/usr/bin/node
const request = require("request");
const movieId = process.argv[2];

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const movie = JSON.parse(body);
    movie.characters.forEach(characterUrl => {
      request(characterUrl, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          const character = JSON.parse(body);
          console.log(character.name);
        }
      });
    });
  }
});
