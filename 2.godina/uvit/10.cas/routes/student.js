const express = require("express");
const path = require('path')

const router = express.Router();

const studentController = require('../controllers/student.js')


router.post("/student", studentController.getStudentByUsername)
router.post("/student/delete/:indeks", studentController.obrisiPodatke)

module.exports = router;