document.querySelector('header nav .hamburg').onclick = function () {
    document.querySelector('header nav ul').classList.toggle('show');
    span = this.querySelector('span');
    span.innerHTML = span.innerHTML == 'menu' ? 'close' : 'menu';
}
window.onload = function () {
    document.querySelector('main').onclick = hide;
    document.querySelector('footer').onclick = hide;
}
function hide() {
    document.querySelector('header nav ul').classList.remove('show');
}
window.onscroll = scroll;
function scroll() {
    if (window.scrollY >= 100) {
        document.querySelector('header nav').classList.add('scroll');
    }
    else {
        document.querySelector('header nav').classList.remove('scroll');
    }
    if (window.scrollY >= 300) {
        document.querySelector('div#up').classList.remove('hide');
    }
    else {
        document.querySelector('div#up').classList.add('hide');
    }
}