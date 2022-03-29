const db = require('../database');

const kortti = {
	getById: function(id, callback) {
		return db.query('select * from kortti where idkortti=?', [id], callback);
	},
	getAll: function(callback) {
		return db.query('select * from kortti', callback);
	},
	add: function(kortti, callback) {
		return db.query(
			'insert into kortti (pin,asiakas_idasiakas,tili_idtili) values(?,?,?)',
			[kortti.pin, kortti.asiakas, kortti.tili],
			callback
		);
	},
	delete: function(id, callback) {
		return db.query('delete from kortti where idkortti=?', [id], callback);
	},
	update: function(id, kortti, callback) {
		return db.query(
			'update kortti set pin=?, asiakas_idasiakas=?, tili_idtili=? where idkortti=?',
			[kortti.pin, kortti.asiakas, kortti.tili, id],
			callback
		);
	}
};
module.exports = kortti;
