function calculateSalary() {
    const baseSalary = 200;
    const commissionRate = 0.09;
    const sales = Number(document.getElementById("sales").value);
    const salary = Math.trunc(baseSalary + sales * commissionRate);
    const salaryRange = getSalaryRange(salary);
    updateTable(salaryRange);
  }
  
  function getSalaryRange(salary) {
    if (salary >= 1000) {
      return "$1000 and over";
    } else if (salary < 1000 && salary>=900) {
        return "$900 to 999";
      } else if (salary < 700 && salary>=600) {
        return "$600 and 699";
      }  else if (salary < 900 && salary>=800) {
        return "$600 and 699";
      }else if (salary < 800 && salary>=700) {
        return "$600 and 699";}
 else if (salary < 600 && salary>=500) {
        return "$500 and 599";
      } else if (salary < 500 && salary>=400) {
        return "$400 and 499";
      } else if (salary < 400 && salary>=300) {
        return "$300 and 399";
      } else if (salary < 300 && salary>=200) {
        return "$200 and 299";
      } else if(salary < 200 && salary>=100) {
        return "$100 and 199";
      }
  }

  
  function updateTable(salaryRange) {
    const table = document.getElementById("result");
    const row = table.rows.namedItem(salaryRange);
    if (row) {
      row.cells[1].textContent = Number(row.cells[1].textContent) + 1;
    } else {
      const newRow = table.insertRow();
      newRow.setAttribute("id", salaryRange);
      const rangeCell = newRow.insertCell();
      rangeCell.textContent = salaryRange;
      const countCell = newRow.insertCell();
      countCell.textContent = 1;
    }
  }
  