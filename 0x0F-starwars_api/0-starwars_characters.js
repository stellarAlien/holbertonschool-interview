#!/usr/bin/node
import request from 'request';
const episode = process.argv[2];

const Print_Names = (names, i = 0) => {
	if (!names[i]) return;
	request(names[i], (error, response, body) => {
		if (error) throw error;
		console.log(JSON.parse(body).name);
		Print_Names(names, i + 1);
	});
};

url = `https://swapi-api.hbtn.io/api/films/${episode}`

request(url, (error, response, body) => {
	if (error) throw error;
	const characters = JSON.parse(body).characters;
	Print_Names(characters);
});
