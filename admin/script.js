async function getCurrentFileContent(owner, repo, filePath, accessToken) {
    console.log(filePath);
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

async function updateFileContent(owner, repo, filePath, accessToken, data, date, place, content) {
    const currentContent = atob(data.content);
    const newContent = currentContent + '\nThis is the updated content';
    const encodedContent = btoa(newContent);
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
        ACCESS_TOKEN = await fetch(`https://simonpucheu.000webhostapp.com/IngeniumTeam/github_token.php?key=${fd.get('password')}`);
    } catch (error) {
        alert(error.message);
        return;
    }
    console.log(ACCESS_TOKEN);
    try {
        const fileData = await getCurrentFileContent('IngeniumTeam', 'ingeniumteam.github.io', fd.get('lang') + '/index.html', ACCESS_TOKEN);
        await updateFileContent('IngeniumTeam', 'ingeniumteam.github.io', fd.get('lang'), ACCESS_TOKEN, fileData, fd.get('date'), fd.get('place'), fd.get('content'));
    } catch (error) {
        alert(error.message);
    }
};