const express = require('express');
const path = require('path')

const studentRoutes = require('./routes/student')

const app = express();

app.use(express.static(path.join(__dirname, "public")))

app.use(express.urlencoded({extended :true}));

app.use(studentRoutes);

app.use('/hello-world', function(req, res, next){

    res.sendFile(path.join(__dirname, "public", "index.html"))

})




module.exports = app;