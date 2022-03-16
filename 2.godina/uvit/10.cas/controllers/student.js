const studentModul = require('../modules/studenti.js');

function getStudentByUsername(req, res, next){

    const username = req.body.username;
    const password = req.body.password;

    const student = studentModul.getStudent(username);
    const proveraSifre = studentModul.proveriSifru(student, password);

    if(proveraSifre)
        res.render('student.ejs', {

            student: student,
            username: username,
            password: password
        })
    else
        res.render('error.ejs', {
            student: student,
            username: username,
            password: password
        })

}

function obrisiPodatke(req, res, next){

    const indeks = req.body.indeks;
    studentModul.obrisiPodatke(indeks);

    res.redirect("/index.html")

}


module.exports = {

    getStudentByUsername,
    obrisiPodatke

}