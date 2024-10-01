MAIN=main.cpp
APP=example

if [ ! -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP
