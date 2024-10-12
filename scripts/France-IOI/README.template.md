# France-IOI Solutions

Accepted solutions of [France-IOI problemset](https://www.france-ioi.org/algo/chapters.php).

## Table of Contents

{% for level, chapters in levels.items() %}
- [{{ level }}](#{{ level | escape_internal_link }})
{% for chapter, problems in chapters.items() %} 
    - [{{ chapter }}](#{{ chapter | escape_internal_link }})
{% endfor %}
{% endfor %}

---

{% for level, chapters in levels.items() %}

## {{ level }}

{% for chapter, content in chapters.items() %}

### {{ chapter }}

{% for problem in content.problems %}
1. <a href="{{ level | escape_external_link }}/{{ chapter | escape_external_link }}/{{ problem.title | escape_external_link }}.{{ problem.extension }}"> 💻 {{ problem.title }} </a>
{% endfor %}

{% for part in content.parts %}

1. **{{ part.part }}**

{% for subproblem in part.problems %}
    1. <a href="{{ level | escape_external_link }}/{{ chapter | escape_external_link }}/{{ part.part | escape_external_link }}/{{ subproblem.title | escape_external_link }}.{{ subproblem.extension }}"> 💻 {{ subproblem.title }} </a>
{% endfor %}

{% endfor %}
{% endfor %}
{% endfor %}
