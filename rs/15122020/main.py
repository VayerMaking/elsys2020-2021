from flask import Flask, render_template, request, flash, redirect, url_for
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SECRET_KEY'] = 'you-will-never-guess'
db = SQLAlchemy(app)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///todo.db'


class Note(db.Model):
    id = db.Column(db.Integer, primary_key = True)
    note_text = db.Column(db.String(100))

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == "POST":
      data = request.form
      note = Note(note_text=data['todoitem'])
      db.session.add(note)
      db.session.commit()
      return redirect(url_for('index'))
      #return render_template('index.html')
    elif request.method == "GET":
      result = Note.query.all()
      return render_template('index.html', result=result)


if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)
