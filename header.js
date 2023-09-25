document.querySelector('header nav .hamburg span').onclick = function () {
    document.querySelector('header nav ul').classList.toggle('show');
    refresh();
}
function refresh () {
    document.querySelector('header nav .hamburg span').innerHTML = document.querySelector('header nav ul').classList.contains('show') ? 'close' : 'menu';
}
window.onload = function () {
    document.body.querySelector('main').onclick = hide;
    document.body.querySelector('footer').onclick = hide;
}
function hide() {
    document.querySelector('header nav ul').classList.remove('show');
    refresh();
}
window.onscroll = scroll;
function scroll() {
    hide();
    if (window.scrollY != 0) {
        document.querySelector('header nav').classList.add('scroll');
    }
    else {
        document.querySelector('header nav').classList.remove('scroll');
    }
    if (window.scrollY >= 300) {
        document.querySelector('.goup').classList.remove('hide');
    }
    else {
        document.querySelector('.goup').classList.add('hide');
    }
}