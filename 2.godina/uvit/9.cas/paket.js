let studenti = [

    {
        ime: "Pera",
        indeks: 20200001
    },

    {
        ime: "Ana",
        indeks: 20200002

    },

    {
        ime: "Mika",
        indeks: 20200003

    },

]

let BROJ_STUDENATA = { broj: studenti.length};

function dodajStudenta(ime, indeks){
    studenti.push({ime, indeks})
    BROJ_STUDENATA++;
}

function nadjiStudenta(indeks){
    for(const student of studenti){
        if(studenti.indeks == indeks){
            return student;
        }
    }

    return null;
}

// module.exports.dodajStudenta = dodajStudenta;
// module.exports.nadjiStudenta = nadjiStudenta;

module.exports = {

    dodajStudenta,
    nadjiStudenta,
    brojStudenata: BROJ_STUDENATA

}