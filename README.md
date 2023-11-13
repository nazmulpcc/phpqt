# PHP QT

This is a "Proof of concept" of a [QT](https://qt.io) binding for PHP 8+.

## Steps to Run

This is a PHP extension developed in C++ and currently tested on MacOS and Linux. Since PHP doesn't support C++ and the extension development process has very limited documentation, I've used [PHP-CPP](https://www.php-cpp.com/) library to develop this POC. You can run the following commands to compile PHP-CPP,

```sh
git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
cd PHP-CPP
git checkout master
make && sudo make install
```

This will clone, compile & install PHP-CPP in your system. You will also need `make` and `g++` commands installed.

Now before you compile this extension, you need to install `qt5` and headers. This can be done with,

```sh
brew install qt@5
# OR for arch-based distro
sudo pacman -S qt5-base
```

Go ahead and compile this repo,

```sh
git clone https://github.com/nazmulpcc/phpqt.git
cd phpqt
make && sudo make install
```

This will compile the extension to a file called *phpqt.so* and put it in php's extension directory (`php-config --extension-dir`). This will also create a ini file called `phpqt.ini` (which loads the extension). If for some reason the *Makefile* cannot put these files in the correct location, you can manually copy them to the right location.

## Usage
Once installed, you can see which classes and methods are available from [here](https://github.com/nazmulpcc/phpqt-demo/tree/master/phpqt). A demo using this extension is available [here](https://github.com/nazmulpcc/phpqt-demo).

## Known Issues

- In some cases, automatic extension installation fails, if that happens to you, you can put the `.so` and `.ini` files in the correct location manually.
- In my experiments, the extension is very stable on MacOS (M1). In linux, it crashes 1 out of 4 times. This used to be a lot worse but improved gradually.
- Only a handful of classes from the QT framework have been ported to PHP since this is just a Proof of concept.
- In some cases, using multiple threads via the `Thread` classes causes memory error.


## WHY??!!
Why not? PHP is a very matured language and you can do some wild things with PHP. You can create [a websocket server](http://socketo.me/docs/websocket), [machine learning](https://php-ml.readthedocs.io/en/latest/), high performance [async IO library](https://reactphp.org/), [proxy server](https://github.com/leproxy/leproxy), [async imap client](https://github.com/nazmulpcc/imap) and many many more. So why not a native desktop application?

## Future Plan
This POC was created because I wanted to create a few small gui workflows and I did not want to use electron or another JS based solution. If I find sufficient interest from the PHP community or I need this myself in the future, I will continue investing time and see what it becomes. Personally, I beleive there is a lot of potential here as PHP is very easy to learn, fun to work with and it has a HUGE eco system.
For me, I will probably implement things like, printing support, a few more widget classes, bluetooth connectivity, qt's network module etc.
