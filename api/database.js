const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'db',
  password: 'dbpassdb',
  database: 'mydb'
});
module.exports = connection;
