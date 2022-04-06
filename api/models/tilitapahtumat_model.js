const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (paiv/klo,tapahtuma,summa,tili_idtili) values(?,?,?,?)',
      [tilitapahtumat.paivklo, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.tili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set paiv/klo=?,tapahtuma=?,summa=?,tili_idtili=? where idtilitapahtumat=?',
      [tilitapahtumat.paivklo, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.tili],
      callback
    );
  }
};
module.exports = tilitapahtumat;