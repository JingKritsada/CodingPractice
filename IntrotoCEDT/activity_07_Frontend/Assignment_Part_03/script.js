document.addEventListener('DOMContentLoaded', () => {
    const itemTable = document.getElementById('itemlist-table');
    const summaryTableBody = document.querySelector('#summary-table tbody');
    const nameSelect = document.getElementById('name-to-add');
    const members = [
        'Karin Sitthibut',
        'Aimeric Supasuth',
        'Punyata Testosaporn',
        'Natthanicha Jamjuree',
        'Kritsada Limsripraphan'
    ];

    function updateSummary() {
        const rows = itemTable.querySelectorAll('tbody tr');
        const totals = {};
        let grandTotal = 0;

        // Calculate totals for each person
        rows.forEach(row => {
            const name = row.cells[1].innerText;
            const price = parseFloat(row.cells[2].innerText);
            if (!totals[name]) {
                totals[name] = 0;
            }
            totals[name] += price;
            grandTotal += price;
        });

        // Clear existing summary
        summaryTableBody.innerHTML = '';

        // Populate summary table
        Object.keys(totals).forEach(name => {
            const row = document.createElement('tr');
            const nameCell = document.createElement('td');
            const totalCell = document.createElement('td');
            nameCell.innerText = name;
            totalCell.innerText = totals[name].toFixed(2);
            row.appendChild(nameCell);
            row.appendChild(totalCell);
            summaryTableBody.appendChild(row);
        });

        // Add total row
        const totalRow = document.createElement('tr');
        const totalNameCell = document.createElement('td');
        const totalAmountCell = document.createElement('td');
        totalNameCell.innerText = 'รวมทั้งหมด';
        totalNameCell.style.fontWeight = 'bold';
        totalAmountCell.innerText = grandTotal.toFixed(2);
        totalAmountCell.style.fontWeight = 'bold';
        totalRow.appendChild(totalNameCell);
        totalRow.appendChild(totalAmountCell);
        summaryTableBody.appendChild(totalRow);

        // If no data, show placeholder
        if (summaryTableBody.childElementCount === 0) {
            const row = document.createElement('tr');
            const cell = document.createElement('td');
            cell.colSpan = 2;
            cell.innerText = 'No data available';
            cell.style.textAlign = 'center';
            row.appendChild(cell);
            summaryTableBody.appendChild(row);
        }
    }

    function addItem() {
        const itemName = document.getElementById('itemname-input').value;
        const itemOwner = document.getElementById('name-to-add').value;
        const itemPrice = parseFloat(document.getElementById('price-to-add').value);
        if (itemName && itemOwner && !isNaN(itemPrice)) {
            const newRow = document.createElement('tr');
            newRow.className = 'item';
            newRow.innerHTML = `
                <td>${itemName}</td>
                <td>${itemOwner}</td>
                <td>${itemPrice.toFixed(2)}</td>
                <td><button class="deletebutton">ลบ</button></td>
            `;
            itemTable.querySelector('tbody').appendChild(newRow);
            document.getElementById('itemname-input').value = '';
            document.getElementById('price-to-add').value = '';
            updateSummary();
        }
    }

    function deleteItem(event) {
        if (event.target.classList.contains('deletebutton')) {
            event.target.closest('tr').remove();
            updateSummary();
        }
    }

    // Populate the dropdown with member names
    members.forEach(member => {
        const option = document.createElement('option');
        option.value = member;
        option.innerText = member;
        nameSelect.appendChild(option);
    });

    itemTable.addEventListener('click', deleteItem);
    document.getElementById('addbutton').addEventListener('click', addItem);

    // Initialize the summary table on page load
    updateSummary();
});