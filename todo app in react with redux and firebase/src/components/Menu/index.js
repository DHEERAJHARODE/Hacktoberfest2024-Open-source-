import { AiOutlineBars, AiOutlineFolder, AiOutlinePaperClip } from 'react-icons/ai';
import { BsLightningCharge } from 'react-icons/bs';
import { FaRegChartBar } from 'react-icons/fa';
import { HiOutlinePhotograph } from 'react-icons/hi';
import './style.css';
export default function Menu({ children }) {
    return (
        <div className="vh-100 menu-bg">
            <div className='d-flex flex-column align-items-center'>
                <div className='icons'>
                    <AiOutlineBars size='32px' color='#ddd7d7' />
                </div>
                <div className="icons my-2">
                    <BsLightningCharge size='32px' color="#dacd3f" />
                </div>
                <div className="icons my-2">
                    <AiOutlineFolder size='32px' color="#ddd7d7" />
                </div>
                <div className="icons my-2">
                    <FaRegChartBar size='32px' color="#ddd7d7" />
                </div>
                <div className="icons my-2">
                    <HiOutlinePhotograph size='32px' color="#ddd7d7" />
                </div>
                {children}
                <div className="icons my-2">
                    <AiOutlinePaperClip size='32px' color="#ddd7d7" />
                </div>
            </div>
        </div>
    )
}