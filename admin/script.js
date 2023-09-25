async function getCurrentFileContent(owner, repo, filePath, accessToken) {
    const response = await fetch(`https://api.github.com/repos/${owner}/${repo}/contents/${filePath}`, {
        method: 'GET',
        headers: {
            'Authorization': `Bearer ${accessToken}`,
            'Accept': 'application/vnd.github.v3+json',
        },
    });

    if (response.status === 200) {
        const data = await response.json();
        return data;
    } else {
        throw new Error(`Error getting file content: ${response.statusText}`);
    }
}

async function updateFileContent(owner, repo, filePath, accessToken, data, lang, date, place, content) {
    const currentContent = atob(data.content);
    const fileData = await getCurrentFileContent(owner, repo, filePath, accessToken);
    const parser = new DOMParser();
    const doc = parser.parseFromString(currentContent, 'text/html');
    const eventsContainer = doc.querySelector('.events');
    const newEventDiv = document.createElement('div');
    newEventDiv.classList.add('event');
    newEventDiv.innerHTML = `
    <input type="date" value="${date}" readonly class="date">
    <span class="place">${place}</span>
    <span class="content">${content}</span>
  `;
    const existingEvent = eventsContainer.querySelector(`.event input.date[value="${date}"]`);
    if (existingEvent) {
        existingEvent.closest('.event').replaceWith(newEventDiv);
    } else {
        eventsContainer.appendChild(newEventDiv);
    }
    const updatedContent = new XMLSerializer().serializeToString(doc);
    console.log(updatedContent);
    const encodedContent = btoa(updatedContent.replace('Â', ''));
    await updateFileContent(owner, repo, filePath, accessToken, fileData, 'HTML Update', date, place, encodedContent);
    const commitMessage = `Update ${lang}/index.html ${date}`;
    const response = await fetch(`https://api.github.com/repos/${owner}/${repo}/contents/${filePath}`, {
        method: 'PUT',
        headers: {
            'Authorization': `Bearer ${accessToken}`,
            'Accept': 'application/vnd.github.v3+json',
        },
        body: JSON.stringify({
            message: commitMessage,
            content: encodedContent,
            sha: data.sha,
        }),
    });

    if (response.status === 200) {
        console.log('File updated successfully');
    } else {
        throw new Error(`Error updating file: ${response.statusText}`);
    }
}

document.querySelector('form').onsubmit = async function () {
    var fd = new FormData(this);
    var ACCESS_TOKEN;
    try {
        ACCESS_TOKEN = await (await fetch(`https://simonpucheu.000webhostapp.com/IngeniumTeam/github_token.php?key=${fd.get('password')}`)).text();
    } catch (error) {
        alert(error.message);
        return;
    }
    try {
        const fileData = await getCurrentFileContent('IngeniumTeam', 'ingeniumteam.github.io', fd.get('lang') + '/index.html', ACCESS_TOKEN);
        await updateFileContent('IngeniumTeam', 'ingeniumteam.github.io', fd.get('lang') + '/index.html', ACCESS_TOKEN, fileData, fd.get('lang'), fd.get('date'), fd.get('place'), fd.get('content'));
    } catch (error) {
        alert(error.message);
    }
};