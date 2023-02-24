const carousel = document.querySelector('.carousel');
const container = document.querySelector('.carousel-container');
const items = document.querySelectorAll('.carousel-item');
const prevBtn = document.querySelector('.prev');
const nextBtn = document.querySelector('.next');

let index = 0;
let interval = 0;

function updateCarousel() {
    container.style.transform = `translateX(${-index * carousel.offsetWidth}px)`;
}

function setActiveItem() {
    items.forEach(item => item.classList.remove('active'));
    items[index].classList.add('active');
}

function autoScroll() {
    if (interval != 0) return;
    interval = setInterval(() => {
        index++;
        if (index >= items.length) {
            index = 0;
        }
        updateCarousel();
        setActiveItem();
    }, 4000);
}

prevBtn.addEventListener('click', () => {
    index--;
    if (index < 0) {
        index = items.length - 1;
    }
    clearInterval(interval);
    interval = 0;
    setTimeout(autoScroll, 5000);
    updateCarousel();
    setActiveItem();
});

nextBtn.addEventListener('click', () => {
    index++;
    if (index >= items.length) {
        index = 0;
    }
    clearInterval(interval);
    interval = 0;
    setTimeout(autoScroll, 5000);
    updateCarousel();
    setActiveItem();
});

setActiveItem();
autoScroll();
