function calculateFromForm(form, cakesTotal, basketTotal, funnyActionTotal, bonus, rawTotal, total) {
    const formData = new FormData(form);
    const calcul = calculate(parseInt(formData.get('cakesLegendaryRecipe')), parseInt(formData.get('cakesLayers')), parseInt(formData.get('cakesCherries')), Boolean(formData.get('basketPresent')), Boolean(formData.get('basketCountIsGood')), parseInt(formData.get('basketCherries')), Boolean(formData.get('funnyActionDone')), parseInt(formData.get('estimation')));
    cakesTotal.value = calcul.cakesTotal;
    basketTotal.value = calcul.basketTotal;
    funnyActionTotal.value = calcul.funnyActionTotal;
    bonus.value = calcul.bonus;
    rawTotal.value = calcul.rawTotal;
    total.value = calcul.total;
}

function reverseFromForm(form, rawTotal) {
    const formData = new FormData(form);
    rawTotal.value = revere(parseInt(formData.get('total')), parseInt(formData.get('estimation'))).rawTotal;
}

function calculate(cakesLegendaryRecipe, cakesLayers, cakesCherries, basketPresent, basketCountIsGood, basketCherries, funnyActionDone, estimation) {
    const cakesTotal = (cakesLegendaryRecipe * 4) + cakesLayers + (cakesCherries * 3);
    const basketTotal = (basketPresent * 5) + ((basketCountIsGood && basketCherries > 0) * 5) + basketCherries;
    const funnyActionTotal = (funnyActionDone * 5);
    const rawTotal = cakesTotal + basketTotal + funnyActionTotal;
    const bonus = calculateBonus(rawTotal, estimation).bonus;
    const total = calculateBonus(rawTotal, estimation).total;
    return { cakesTotal: cakesTotal, basketTotal: basketTotal, funnyActionTotal: funnyActionTotal, bonus: bonus, rawTotal: rawTotal, total: total };
}

function calculateBonus(rawTotal, estimation) {
    const bonus = (20 - (rawTotal >= estimation ? rawTotal - estimation : estimation - rawTotal)) > 0 ? (20 - (rawTotal >= estimation ? rawTotal - estimation : estimation - rawTotal)) : 0;
    const total = rawTotal + bonus;
    return { bonus: bonus, total: total, estimation: estimation, rawTotal: rawTotal };
}

function revere(total, estimation) {
    for (var rawTotal = 0; rawTotal <= 300; rawTotal += 0.5) {
        if (calculateBonus(rawTotal, estimation).total == total) {
            return { total: total, estimation: estimation, rawTotal: rawTotal };
        }
    }
    console.error('Raw total not found');
    return { total: total, estimation: estimation, rawTotal: -1 };
}