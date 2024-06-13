import { db, ref, child, get, auth, onAuthStateChanged } from '../../config';
export const getToDos = (uid) => {
    // console.log('ASYNC DISPATCH')
    return dispatch => {
        const dbRef = ref(db);
         get(child(dbRef, `todos/${uid}`))
            .then(snapshot => {
                // console.log("db connected");
                if (snapshot.exists()) {
                    dispatch({ type: "GET_TASKS", payload: snapshot.val() })
                }
                else {
                    dispatch({ type: "NO_TASKS", payload: 'No tasks found' })
                }
            })
            .catch(err => {
                dispatch({ type: 'DB_FAILED', payload: err })
            })
    }
}

export const addToDoToStore = (todo) => {
    return {
        type: 'ADD_TODO',
        payload: todo
    }
}

export const authUserToStore = (user) => {
    // console.log(user);
    // return{
    //     type: 'AUTH_USER',
    //     payload: user,
    // }
    return async dispatch => {
        const dbRef = ref(db);
        await get(child(dbRef, `users/${user}`))
            .then(snapshot => {
                // console.log("db connected");
                if (snapshot.exists()) {
                    // console.log(snapshot.val());
                    dispatch({ type: "AUTH_USER", payload: snapshot.val() })
                    console.log(snapshot.val());
                }
                else {
                    dispatch({ type: "NO_USER" });
                }
            })
            .catch(err => {
                dispatch({ type: 'NO_USER' })
            })
    }
}