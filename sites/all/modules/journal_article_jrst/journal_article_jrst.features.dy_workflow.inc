<?php

/**
 * Implementation of hook_features_default_workflow().
 */
function journal_article_jrst_features_default_workflow() {
  $workflow = array();

  // Exported workflow type map: Article
  $workflow['Article']['type_map'] = array(
    'article' => 'article',
  );

  // Exported workflow states: Article - (creation)
  $workflow['Article']['(creation)'] = array(
    'workflow_name' => 'Article',
    'state_name' => '(creation)',
    'transitions' => array(
      '(creation)' => array(
        'Review' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'EB Review' => array(
          'author' => 1,
          'site admin' => 1,
        ),
        'Decision' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Published' => array(
          'site admin' => 1,
        ),
      ),
    ),
    'access' => NULL,
  );

  // Exported workflow states: Article - EB Review
  $workflow['Article']['EB Review'] = array(
    'workflow_name' => 'Article',
    'state_name' => 'EB Review',
    'transitions' => array(
      'EB Review' => array(
        'Review' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Decision' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Published' => array(
          'site admin' => 1,
        ),
      ),
    ),
    'access' => array(
      'EB Review' => array(
        'associate editor' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '0',
        ),
        'eb_member' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'editor' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '0',
        ),
        'site admin' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'anonymous user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'authenticated user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'community manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'content manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'reviewer' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'author' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
      ),
    ),
  );

  // Exported workflow states: Article - Review
  $workflow['Article']['Review'] = array(
    'workflow_name' => 'Article',
    'state_name' => 'Review',
    'transitions' => array(
      'Review' => array(
        'EB Review' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Decision' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Published' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
      ),
    ),
    'access' => array(
      'Review' => array(
        'associate editor' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '0',
        ),
        'editor' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '0',
        ),
        'reviewer' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'site admin' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'anonymous user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'authenticated user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'community manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'content manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'eb_member' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'author' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
      ),
    ),
  );

  // Exported workflow states: Article - Decision
  $workflow['Article']['Decision'] = array(
    'workflow_name' => 'Article',
    'state_name' => 'Decision',
    'transitions' => array(
      'Decision' => array(
        'EB Review' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Review' => array(
          'associate editor' => 1,
          'editor' => 1,
          'site admin' => 1,
        ),
        'Published' => array(
          'site admin' => 1,
        ),
      ),
    ),
    'access' => array(
      'Decision' => array(
        'associate editor' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'eb_member' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'editor' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'site admin' => array(
          'grant_view' => '1',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'anonymous user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'authenticated user' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'community manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'content manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'reviewer' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'author' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
      ),
    ),
  );

  // Exported workflow states: Article - Published
  $workflow['Article']['Published'] = array(
    'workflow_name' => 'Article',
    'state_name' => 'Published',
    'transitions' => array(
      'Published' => array(
        'EB Review' => array(
          'site admin' => 1,
        ),
        'Review' => array(
          'site admin' => 1,
        ),
        'Decision' => array(
          'site admin' => 1,
        ),
      ),
    ),
    'access' => array(
      'Published' => array(
        'anonymous user' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'authenticated user' => array(
          'grant_view' => '1',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'associate editor' => array(
          'grant_view' => '0',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'community manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'content manager' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'eb_member' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'editor' => array(
          'grant_view' => '0',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'reviewer' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
        'site admin' => array(
          'grant_view' => '0',
          'grant_update' => '1',
          'grant_delete' => '1',
        ),
        'author' => array(
          'grant_view' => '0',
          'grant_update' => '0',
          'grant_delete' => '0',
        ),
      ),
    ),
  );

  return $workflow;
}
