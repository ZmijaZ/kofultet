const http = require('http');

const app = require('./app.js')

const server = http.createServer(app);

server.listen(3000);

server.once('listening', provera);

function provera(){

    console.log("Server radi na adresi http://localhost:3000!")

}