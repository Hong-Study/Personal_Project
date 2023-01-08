from flask import Flask
from flask import request
from flask import render_template
from flask import jsonify
from flask import make_response


# 로그인 유저 인증 토큰 생성
import jwt
# password 암호화 라이브러리
import bcrypt


SECRET_KEY = "Blue-Bird"
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')
    
if __name__ == "__main__":
    app.run(debug=True)