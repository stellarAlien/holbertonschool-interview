import request from 'request';
import { argv } from 'process';

episode = argv(2);
url = `https://swapi-api.hbtn.io/api/${epsiode}`;
request(url, function (error, response, body)  {
    if (error) throw error;
    let json = JSON.parse(body).characters;
    json.foreach((item, index) => {
        request(item, (error, response, body) => {
            if (error) throw error;

            let n = JSON.parse(body).name;
            console.log(n);
        });
    }       
    );
    
});