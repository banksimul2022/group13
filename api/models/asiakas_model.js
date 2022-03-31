const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where idasiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (nimi,osoite,puhelin) values(?,?,?)',
      [asiakas.nimi, asiakas.osoite, asiakas.puhelin],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where idasiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set nimi=?,osoite=?, puhelin=? where idasiakas=?',
      [asiakas.nimi, asiakas.osoite, asiakas.puhelin, id],
      callback
    );
  }
};
module.exports = asiakas;