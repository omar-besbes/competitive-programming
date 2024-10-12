# CSES Solutions

Accepted solutions of [CSES problemset](https://cses.fi/problemset).

## Table of Contents

{% for category, problems in categories.items() %}

- [{{ category }}](#{{ category | escape_internal_link }})
  {% endfor %}

---

{% for category, problems in categories.items() %}

## {{ category }}

<table>
    <thead>
        <tr>
            <th>Problem ID</th>
            <th>Solution Code</th>
            <th>Problem Statement</th>
        </tr>
    </thead>
    <tbody> {% for problem in problems %}
        <tr>
            <td>
                {{ problem.id }}
            </td>
            <td>
                <a href="{{ category | escape_external_link }}/{{ problem.id }}%20-%20{{ problem.title | escape_external_link }}.cpp">
                    💻 {{ problem.title }}
                </a>
            </td>
            <td>
                <a href="https://cses.fi/problemset/task/{{ problem.id }}" target="_blank">
                    📜 Statement
                </a>
            </td>
        </tr>{% endfor %}
    </tbody>
</table>

{% endfor %}
