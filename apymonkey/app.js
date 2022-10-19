const express = require('express');
const hbs = require('hbs');
const path = require('path');
const bodyparser = require("body-parser");

const app = express()

const partials_path = path.join(__dirname, './src/views/partials');
const public_path = path.join(__dirname, './public');
const views_path = path.join(__dirname, './src/views/pages');

console.log(views_path)
console.log(partials_path)
console.log(public_path)
hbs.registerPartials(partials_path);

app.set('view engine', 'hbs');
app.set('views', views_path);

app.use(express.static(public_path));
app.use(express.json());
app.use(bodyparser.urlencoded({extended: true}));

app.get('/', (req, res) => {
    res.render('index');
})

app.listen(3001, () => {
    console.log('listening on 3001');
})