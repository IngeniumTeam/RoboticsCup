window.addEventListener('DOMContentLoaded', function () {
    const eventss = this.document.querySelectorAll('.events');
    this.fetch('/admin/db.json').then((response) => { return response.json(); }).then((json) => {
        eventss.forEach((events) => {
            json[events.getAttribute('data-year')].forEach((key, eventData) => {
                const event = this.document.createElement('div');
                event.classList = 'event';
                const date = this.document.createElement('input');
                date.type = 'date';
                date.classList = 'date';
                date.readOnly = 'true';
                date.value = key;
                const place = this.document.createElement('span');
                place.classList = 'place';
                place.textContent = eventData.place;
                const content = this.document.createElement('span');
                content.classList = 'content';
                content.textContent = eventData[this.document.documentElement.getAttribute('lang')];
                events.appendChild(event);
                event.appendChild(date);
                event.appendChild(place);
                event.appendChild(content);
            });
        });
    });
});