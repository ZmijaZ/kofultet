const studenti = [

    {username: "mi2020001", password: "123", name: "Marija"},
    {username: "mi2020002", password: "456", name: "Ana"},
    {username: "mi2020003", password: "789", name: "Marjan"}

]

function getStudent(username){

    let student = null;

    for(const stud of studenti)
         if(stud.username === username)
            student = stud;

    return student;
}

function proveriSifru(student, password){

    return student.password === password;

}

function obrisiPodatke(indeks){

    for(let i = 0; i<studenti.length; i++)
        if(studenti[i].indeks === indeks)
            studenti.splice(i, 1);

}


module.exports = {

    getStudent,
    proveriSifru,
    obrisiPodatke

}