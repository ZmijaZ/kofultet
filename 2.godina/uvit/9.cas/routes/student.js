const express = require("express");
const path = require('path')

const router = express.Router();

router.post("/student", function(req, res, next){

    const data = req.body;
    console.log("Username:", data.username);
    console.log("Passowrd:", data.password);

    res.sendFile(path.join(__dirname, "..", "public", "student.html"))

});

module.exports = router;