# node-gyp依赖python环境
FROM gastrodia/python

WORKDIR /container

# 安装npm模块
ADD package.json /container/package.json

# 使用淘宝的npm镜像
#RUN npm install --production -d --registry=https://registry.npm.taobao.org
RUN wget https://npm.taobao.org/mirrors/node/latest-v7.x/node-v7.5.0-linux-x64.tar.gz && \
    tar -C /usr/local --strip-components 1 -xzf node-v7.5.0-linux-x64.tar.gz && \
    rm node-v7.5.0-linux-x64.tar.gz 

RUN npm install -g nodemon --registry=https://registry.npm.taobao.org
RUN npm install lwip --registry=https://registry.npm.taobao.org
RUN npm install --registry=https://registry.npm.taobao.org

WORKDIR /container/app

# 添加源代码
ADD . /container/app

# 运行app.js
CMD ["nodemon", "index.js"]