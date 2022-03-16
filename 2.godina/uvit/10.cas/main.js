const paket = require('./paket');

console.log(`Trenutno ima ${paket.brojStudenata.broj} studenata`)

paket.dodajStudenta('Marija', 20200004);
console.log(paket.nadjiStudenta(20200003));
console.log(`Trenutno ima ${paket.brojStudenata.broj} studenata`)
