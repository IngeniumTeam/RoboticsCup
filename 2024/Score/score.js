function calculateFromForm(form, planteTotal, pamiTotal, panneauSolaireTotal, bonus, rawTotal, total) {
    const formData = new FormData(form);
    const calcul = calculate(parseInt(formData.get('plante')), parseInt(formData.get('pot')),parseInt(formData.get('jardiniere')), parseInt(formData.get('pami')), parseInt(formData.get('pamiContact')), parseInt(formData.get('panneauSolaire')), parseInt(formData.get('estimation')));
    planteTotal.value = calcul.planteTotal;
    pamiTotal.value = calcul.pamiTotal;
    panneauSolaireTotal.value = calcul.panneauSolaireTotal;
    bonus.value = calcul.bonus;
    rawTotal.value = calcul.rawTotal;
    total.value = calcul.total;
}

function reverseFromForm(form, rawTotal) {
    const formData = new FormData(form);
    rawTotal.value = revere(parseInt(formData.get('total')), parseInt(formData.get('estimation'))).rawTotal;
}

function calculate(plante, pot, jardiniere, pami, pamiContact, panneauSolaire, estimation) {
    const planteTotal = plante + (pot * 3) + jardiniere;
    const pamiTotal = (pami + pamiContact) * 5;
    const panneauSolaireTotal = panneauSolaire * 5;
    const rawTotal = planteTotal + pamiTotal + panneauSolaireTotal;
    const bonus = calculateBonus(rawTotal, estimation).bonus;
    const total = calculateBonus(rawTotal, estimation).total;
    return { planteTotal: planteTotal, pamiTotal: pamiTotal, panneauSolaireTotal: panneauSolaireTotal, bonus: bonus, rawTotal: rawTotal, total: total };
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