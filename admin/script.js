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
    const currentContent = JSON.parse(atob(data.content));
    if (place != '') {
        currentContent[date]['place'] = place;
    }
    currentContent[date][lang] = content;
    const encodedContent = btoa(JSON.stringify(currentContent));
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
        const fileData = await getCurrentFileContent('IngeniumTeam', 'ingeniumteam.github.io', 'admin/db.json', ACCESS_TOKEN);
        await updateFileContent('IngeniumTeam', 'ingeniumteam.github.io', 'admin/db.json', ACCESS_TOKEN, fileData, fd.get('lang'), fd.get('date'), fd.get('place'), fd.get('content'));
    } catch (error) {
        alert(error.message);
    }
};

// function stringToUtf8Bytes(str) {
//     const utf8Encoder = new TextEncoder('utf-8');
//     return utf8Encoder.encode(str);
// }

// function uint8ArrayToBase64(uint8Array) {
//     const byteArray = Array.from(uint8Array);
//     const binaryString = String.fromCharCode.apply(null, byteArray);
//     return btoa(binaryString);
// }

// function stringToBase64(str) {
//     const utf8Bytes = stringToUtf8Bytes(str);
//     return uint8ArrayToBase64(utf8Bytes);
// }
