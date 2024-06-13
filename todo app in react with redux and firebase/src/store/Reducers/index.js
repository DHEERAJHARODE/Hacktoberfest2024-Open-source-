let INITIAL_STAGE= {authStatus: false};
const reducerFunction = (state = INITIAL_STAGE, action)=>{
    switch (action.type){
        case 'GET_TASKS':
            return {
                ...state,
                tasks: action.payload
            }
        case 'NO_TASKS':
            return {
                ...state,
                tasks: action.payload
            }
        case 'ADD_TODO':
            return {
                ...state,
                tasks: action.payload
            }
        case 'DB_FAILED':
            return {
                ...state,
                tasks: action.payload
            }
        case 'AUTH_USER':
            console.log(state);
            return {
                ...state,
                user: action.payload,
                authStatus: true
            }
        case 'NO_USER':
            return {
                authStatus: false
            }
        default:
            return state
    }
}

export default reducerFunction;