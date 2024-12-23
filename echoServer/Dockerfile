FROM ubuntu:18.04

ENV TZ=Europe/Moscow  

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
RUN apt-get update  && apt-get install -y build-essential
RUN apt-get install qt5-default -y  
RUN apt-get install qtbase5-dev -y  
RUN apt-get install qt5-qmake  
RUN apt-get install build-essential -y

LABEL author="Kulibabaev Amir" \
           group="231-3213"

RUN mkdir ./Kulibabaev
WORKDIR /Kulibabaev

COPY . /Kulibabaev

RUN qmake echoServer.pro
RUN make

RUN mv echoServer ProgToStart

EXPOSE 33333

ENTRYPOINT ["/Kulibabaev/ProgToStart"]