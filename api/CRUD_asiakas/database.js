const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'netuser4',
  password: 'netpass',
  database: 'netdb4'
});
module.exports = connection;