# France-IOI Solutions

Accepted solutions of [France-IOI problemset](https://www.france-ioi.org/algo/chapters.php).

## Table of Contents

{% for level, chapters in levels.items() %}
- [{{ level }}](#{{ level | lower | replace(' ', '-') }})
{% for chapter, problems in chapters.items() %} 
    - [{{ chapter }}](#{{ chapter | lower | replace(' ', '-') }})
{% endfor %}
{% endfor %}

---

{% for level, chapters in levels.items() %}

## {{ level }}

{% for chapter, problems in chapters.items() %}

### {{ chapter }}

{% for problem in problems %}
1. <a href="{{ level | replace(' ', '%20') }}/{{ chapter | replace(' ', '%20') }}/{{ problem.title | replace(' ', '%20') }}.cpp"> 💻 {{ problem.title }} </a>
{% endfor %}

{% endfor %}
{% endfor %}
